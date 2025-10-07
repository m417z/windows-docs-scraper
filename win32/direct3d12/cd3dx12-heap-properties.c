struct CD3DX12_HEAP_PROPERTIES  : public D3D12_HEAP_PROPERTIES{
       CD3DX12_HEAP_PROPERTIES();
       explicit CD3DX12_HEAP_PROPERTIES(const D3D12_HEAP_PROPERTIES &o);
       CD3DX12_HEAP_PROPERTIES(D3D12_CPU_PAGE_PROPERTY cpuPageProperty, D3D12_MEMORY_POOL memoryPoolPreference, UINT creationNodeMask = 1, UINT nodeMask = 1);
       explicit CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE type, UINT creationNodeMask = 1, UINT nodeMask = 1);
       operator const D3D12_HEAP_PROPERTIES&() const;
  bool inline operator==( const D3D12_HEAP_PROPERTIES& l, const D3D12_HEAP_PROPERTIES& r );
  bool inline operator!=( const D3D12_HEAP_PROPERTIES& l, const D3D12_HEAP_PROPERTIES& r );
};