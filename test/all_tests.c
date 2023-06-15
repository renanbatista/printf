#include "unity_fixture.h"

TEST_GROUP_RUNNER(xxx)
{
	RUN_TEST_CASE(xxx, xxxx);
}

static void	run_all_tests(void)
{
	RUN_TEST_GROUP(xxx);
}

int	main(int argc, const char *argv[])
{
	return (UnityMain(argc, argv, run_all_tests));
}