HRESULT RetrieveDescriptor(
  [in]      UCHAR  DescriptorType,
  [in]      UCHAR  Index,
  [in]      USHORT LanguageID,
  [in, out] ULONG  *BufferLength,
  [out]     PVOID  Buffer
);