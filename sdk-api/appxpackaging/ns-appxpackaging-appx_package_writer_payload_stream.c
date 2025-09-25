typedef struct APPX_PACKAGE_WRITER_PAYLOAD_STREAM {
  IStream                 *inputStream;
  LPCWSTR                 fileName;
  LPCWSTR                 contentType;
  APPX_COMPRESSION_OPTION compressionOption;
} APPX_PACKAGE_WRITER_PAYLOAD_STREAM;