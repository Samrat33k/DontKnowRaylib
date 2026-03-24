// Copyright (c) 2026-Present Jogeshwar Digital Pvt. Ltd. | Brahmanda Engine. All rights reserved.

#pragma once

#include <array>
#include <memory>
#include <type_traits>
#include <cassert>

#include "LayerInitData.h"


//...

namespace Brahmanda
{
	class WorldLayer;
	class AssetManager;

	enum class ELayerCollectionType
	{
		ELCT_NONE = 0,
		ELCT_Interior,
		ELCT_Exterior,
		ELCT_LightsOnly,
	};

	template <size_t N>
	struct WorldLayerCollection
	{
	public:

		WorldLayerCollection() = default;
		~WorldLayerCollection() = default;

		WorldLayer* GetLayerAt(size_t InIndex)
		{
			assert(InIndex < MaxSize);
			return WorldLayerList[InIndex].get();
		}

		const WorldLayer* GetLayerAtConst(size_t InIndex) const
		{
			assert(InIndex < MaxSize);
			return WorldLayerList[InIndex].get();
		}

		std::array<std::unique_ptr<WorldLayer>, N>& GetLayerList()
		{
			return WorldLayerList;
		}

		const std::array<std::unique_ptr<WorldLayer>, N>& GetLayerListConst() const
		{
			return WorldLayerList;
		}

		template<typename T, typename... Args>
		T& AddLayerAt(size_t InIndex, LayerInitData& InData, Args... InArgs)
		{
			static_assert(std::is_base_of_v<Brahmanda::WorldLayer, T>, "T must derive from WorldLayer");
			assert(InIndex < MaxSize);
			assert(!WorldLayerList[InIndex] && "Layer already exists at Index");

			std::unique_ptr<T> Ptr = std::make_unique<T>(std::forward<LayerInitData>(InData), std::forward<Args>(InArgs)...);
			T& Ref = *Ptr;

			WorldLayerList[InIndex] = std::move(Ptr);
			ActiveSize++;

			return Ref;
		}

		template<typename T, typename... Args>
		T& SetLayerAt(size_t InIndex, LayerInitData& InData, Args... InArgs)
		{
			static_assert(std::is_base_of_v<Brahmanda::WorldLayer, T>, "T must derive from WorldLayer");
			assert(InIndex < MaxSize);

			std::unique_ptr<T> Ptr = std::make_unique<T>(std::forward<LayerInitData>(InData), std::forward<Args>(InArgs)...);
			T& Ref = *Ptr;

			WorldLayerList[InIndex] = std::move(Ptr);

			return Ref;
		}

		void RemoveLayerAt(size_t InIndex)
		{
			assert(InIndex < MaxSize);

			if (WorldLayerList[InIndex])
			{
				WorldLayerList[InIndex].reset();
				ActiveSize--;
			}
		}

		ELayerCollectionType GetLayerCollectionType() const
		{
			return CollectionType;
		}

		void SetLayerCollectionType(ELayerCollectionType InType)
		{
			CollectionType = InType;
		}

	private:

		size_t MaxSize = N;
		size_t ActiveSize = 0U;
		std::array<std::unique_ptr<WorldLayer>, N> WorldLayerList;
		ELayerCollectionType CollectionType = ELayerCollectionType::ELCT_NONE;
	};
}