CXX = g++	# C++ compiler

#Flags
# -O2: Optimize code
# -Wall: Enable all warnings
# -Wno-missing-braces: Disable warning for missing braces
CXXFLAGS = -O2 -Wall -Wno-missing-braces

INCLUDES = -I ../include	# Include directories

# Libraries
# -L ../lib/: Path to the library
# -lraylib: Link to the library
# -lopengl32: Link to the OpenGL library
# -lgdi32: Link to the GDI library
# -lwinmm: Link to the Windows Multimedia library
# -mwindows: Hiện game mà không hiện console
LIBS = -L ../lib -lraylib -lopengl32 -lgdi32 -lwinmm #-mwindows

SRCS = $(wildcard ../src/*.cpp)	# Lôi mọi file từ src
# Đổi tên file từ src thành obj
# cơ bản là chỗ cho files obj sau khi biên dịch
OBJS_DIR = obj
# Thay đổi tên file từ src thành obj
OBJS = $(SRCS:../src/%.cpp=$(OBJS_DIR)/%.o)
TARGET = EA.exe	# Tên file sau khi build

all: $(TARGET) # run
# Tạo file thực thi từ các file obj
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LIBS)

# Biên dịch từng file cpp thành file obj
# Tạo thư mục obj nếu chưa tồn tại
# Biên dịch từng file cpp thành file obj
$(OBJS_DIR)/%.o: ../src/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Chạy file sau khi biên dịch
# run: $(TARGET)
#	./$(TARGET)

# Xoá file obj và file thực thi rồi biên dịch lại
# $(OBJS_DIR)/*.o: xoá tất cả các file obj
# $(TARGET): xoá file thực thi (EA.exe)
# clean:
#	if exist $(OBJS_DIR) del /Q $(OBJS_DIR)\*.o
#	if exist $(TARGET) del /Q $(TARGET)
