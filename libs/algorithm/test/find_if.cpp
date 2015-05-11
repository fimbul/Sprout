/*=============================================================================
  Copyright (c) 2011-2015 Bolero MURAKAMI
  https://github.com/bolero-MURAKAMI/Sprout

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef SPROUT_LIBS_ALGORITHM_TEST_FIND_IF_CPP
#define SPROUT_LIBS_ALGORITHM_TEST_FIND_IF_CPP

#include <sprout/algorithm/find_if.hpp>
#include <sprout/array.hpp>
#include <sprout/container.hpp>
#include <testspr/tools.hpp>

namespace testspr {
	static void algorithm_find_if_test() {
		using namespace sprout;
		{
			SPROUT_STATIC_CONSTEXPR auto arr1 = array<int, 10>{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};

			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find_if(
					sprout::begin(arr1),
					sprout::end(arr1),
					testspr::greater_than<int>(7)
					);
				TESTSPR_BOTH_ASSERT(found == sprout::begin(arr1) + 7);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find_if(
					sprout::begin(arr1),
					sprout::end(arr1),
					testspr::greater_than<int>(10)
					);
				TESTSPR_BOTH_ASSERT(found == sprout::end(arr1));
			}
			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find_if(
					sprout::begin(arr1),
					sprout::begin(arr1) + 5,
					testspr::greater_than<int>(7)
					);
				TESTSPR_BOTH_ASSERT(found == sprout::begin(arr1) + 5);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find_if(
					sprout::begin(arr1),
					sprout::begin(arr1) + 5,
					testspr::greater_than<int>(10)
					);
				TESTSPR_BOTH_ASSERT(found == sprout::begin(arr1) + 5);
			}

			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find_if(
					testspr::reduce_input(sprout::begin(arr1)),
					testspr::reduce_input(sprout::end(arr1)),
					testspr::greater_than<int>(7)
					).base();
				TESTSPR_BOTH_ASSERT(found == sprout::begin(arr1) + 7);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find_if(
					testspr::reduce_input(sprout::begin(arr1)),
					testspr::reduce_input(sprout::end(arr1)),
					testspr::greater_than<int>(10)
					).base();
				TESTSPR_BOTH_ASSERT(found == sprout::end(arr1));
			}
			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find_if(
					testspr::reduce_input(sprout::begin(arr1)),
					testspr::reduce_input(sprout::begin(arr1) + 5),
					testspr::greater_than<int>(7)
					).base();
				TESTSPR_BOTH_ASSERT(found == sprout::begin(arr1) + 5);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find_if(
					testspr::reduce_input(sprout::begin(arr1)),
					testspr::reduce_input(sprout::begin(arr1) + 5),
					testspr::greater_than<int>(10)
					).base();
				TESTSPR_BOTH_ASSERT(found == sprout::begin(arr1) + 5);
			}

			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find_if(
					testspr::reduce_random_access(sprout::begin(arr1)),
					testspr::reduce_random_access(sprout::end(arr1)),
					testspr::greater_than<int>(7)
					).base();
				TESTSPR_BOTH_ASSERT(found == sprout::begin(arr1) + 7);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find_if(
					testspr::reduce_random_access(sprout::begin(arr1)),
					testspr::reduce_random_access(sprout::end(arr1)),
					testspr::greater_than<int>(10)
					).base();
				TESTSPR_BOTH_ASSERT(found == sprout::end(arr1));
			}
			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find_if(
					testspr::reduce_random_access(sprout::begin(arr1)),
					testspr::reduce_random_access(sprout::begin(arr1) + 5),
					testspr::greater_than<int>(7)
					).base();
				TESTSPR_BOTH_ASSERT(found == sprout::begin(arr1) + 5);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto found = sprout::find_if(
					testspr::reduce_random_access(sprout::begin(arr1)),
					testspr::reduce_random_access(sprout::begin(arr1) + 5),
					testspr::greater_than<int>(10)
					).base();
				TESTSPR_BOTH_ASSERT(found == sprout::begin(arr1) + 5);
			}
		}
	}
}	// namespace testspr

#ifndef TESTSPR_CPP_INCLUDE
#	define TESTSPR_TEST_FUNCTION testspr::algorithm_find_if_test
#	include <testspr/include_main.hpp>
#endif

#endif	// #ifndef SPROUT_LIBS_ALGORITHM_TEST_FIND_IF_CPP
