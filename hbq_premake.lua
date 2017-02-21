workspace "HBQ_MATH"
	configurations {"Debug", "Release"}
	platforms {"x32" , "x64"}
	flags {"EnableSSE2" , "FloatStrict"}
	configuration "Debug"
		defines {"DEBUG" , "_DEBUG"}
		flags {"Symbols"}
	configuration "Release"
		defines { "NDEBUG", "NODEBUG" }
		flags { "OptimizeSpeed" }
	configuration "x32"
		architecture "x86"
	configuration "x64"
		architecture "x86_64"
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