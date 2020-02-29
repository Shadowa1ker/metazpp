
cmake_policy(SET CMP0076 NEW)

target_sources(metazpp
	PRIVATE
		src/MZConstants.cpp
		src/MZConstants.hpp
		src/MZStringUtils.hpp
		src/MZTag.cpp
		src/MZTag.hpp
		src/MZTimeCode.cpp
		src/MZTimeCode.hpp
		src/MZTimedTextItem.cpp
		src/MZTimedTextItem.hpp
		src/MZVersion.cpp
		src/MZVersion.hpp
)
