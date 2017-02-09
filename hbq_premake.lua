workspace "HBQ_MATH"
	configurations { "Debug", "Release" }
	defines { "LINUX" }
	-- flags { "EnableSSE2" }
	-- -mfpmath=sse -msse2
	buildoptions { "-mfpmath=sse -msse2 "} -- "-mms-bitfields"

	configuration "Debug"
		defines { "DEBUG", "_DEBUG" }
		buildoptions {"-Wall"  }
	    flags { "Symbols" }
	configuration "Release"
		defines { "NDEBUG", "NODEBUG" }
		optimize "On"
		flags { "Optimize" }
project "hbq_math_searchtable"
	kind "ConsoleApp"
	language "C++" 
	files {"./SourceCode/*.cpp" , "./SourceCode/*.h"}
	removefiles { "SourceCode/hbq_math_lib_numic.cpp" , "SourceCode/hbq_math_lib.cpp"}

project "hbq_math_numerical"
	kind "ConsoleApp"
	language "C++" 
	files {"./SourceCode/**.cpp" , "./SourceCode/*.h"}
	removefiles { "SourceCode/hbq_math_lib_big_table.cpp" , "SourceCode/hbq_math_lib.cpp" }