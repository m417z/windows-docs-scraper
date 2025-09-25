typedef struct _IMAGE_INFO_EX {
  SIZE_T              Size;
  IMAGE_INFO          ImageInfo;
  struct _FILE_OBJECT *FileObject;
} IMAGE_INFO_EX, *PIMAGE_INFO_EX;