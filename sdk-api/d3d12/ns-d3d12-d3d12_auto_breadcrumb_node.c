typedef struct D3D12_AUTO_BREADCRUMB_NODE {
  const char                       *pCommandListDebugNameA;
  const wchar_t                    *pCommandListDebugNameW;
  const char                       *pCommandQueueDebugNameA;
  const wchar_t                    *pCommandQueueDebugNameW;
  ID3D12GraphicsCommandList        *pCommandList;
  ID3D12CommandQueue               *pCommandQueue;
  UINT32                           BreadcrumbCount;
  const UINT32                     *pLastBreadcrumbValue;
  const D3D12_AUTO_BREADCRUMB_OP   *pCommandHistory;
  const D3D12_AUTO_BREADCRUMB_NODE *pNext;
  struct                           D3D12_AUTO_BREADCRUMB_NODE;
} D3D12_AUTO_BREADCRUMB_NODE;