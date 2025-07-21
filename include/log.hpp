#pragma once

/**
 * Defining macros for logging file name and line number
 */
#define LOGOUT std::cout << __FILE__ << " (@" << __LINE__ << "): "
#define LOGERR std::cerr << __FILE__ << " (@" << __LINE__ << "): "
