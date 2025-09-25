typedef struct _CRYPT_XML_OBJECT {
  ULONG                cbSize;
  HCRYPTXML            hObject;
  LPCWSTR              wszId;
  LPCWSTR              wszMimeType;
  LPCWSTR              wszEncoding;
  CRYPT_XML_REFERENCES Manifest;
  CRYPT_XML_BLOB       Encoded;
} CRYPT_XML_OBJECT, *PCRYPT_XML_OBJECT;