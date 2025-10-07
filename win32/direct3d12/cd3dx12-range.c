struct CD3DX12_RANGE  : public D3D12_RANGE{
   CD3DX12_RANGE();
   explicit CD3DX12_RANGE(const D3D12_RANGE &o);
   CD3DX12_RANGE(SIZE_T begin, SIZE_T end);
   operator const D3D12_RANGE&() const;
};