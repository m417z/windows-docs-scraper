struct DSTORAGE_DESTINATION_TEXTURE_REGION {
  ID3D12Resource *Resource;
  UINT           SubresourceIndex;
  D3D12_BOX      Region;
};