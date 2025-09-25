typedef struct D3D11_VIDEO_DECODER_BUFFER_DESC {
  D3D11_VIDEO_DECODER_BUFFER_TYPE BufferType;
  UINT                            BufferIndex;
  UINT                            DataOffset;
  UINT                            DataSize;
  UINT                            FirstMBaddress;
  UINT                            NumMBsInBuffer;
  UINT                            Width;
  UINT                            Height;
  UINT                            Stride;
  UINT                            ReservedBits;
  void                            *pIV;
  UINT                            IVSize;
  BOOL                            PartialEncryption;
  D3D11_ENCRYPTED_BLOCK_INFO      EncryptedBlockInfo;
} D3D11_VIDEO_DECODER_BUFFER_DESC;