typedef struct _NDK_OBJECT_HEADER {
  NDK_VERSION                      Version;
  NDK_OBJECT_TYPE                  ObjectType;
  NDK_OBJECT_HEADER_RESERVED_BLOCK NdkReserved;
} NDK_OBJECT_HEADER;