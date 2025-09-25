typedef struct D3D12_AUTO_BREADCRUMB_NODE1 {
  const char                        *pCommandListDebugNameA;
  const wchar_t                     *pCommandListDebugNameW;
  const char                        *pCommandQueueDebugNameA;
  const wchar_t                     *pCommandQueueDebugNameW;
  ID3D12GraphicsCommandList         *pCommandList;
  ID3D12CommandQueue                *pCommandQueue;
  UINT                              BreadcrumbCount;
  const UINT                        *pLastBreadcrumbValue;
  const D3D12_AUTO_BREADCRUMB_OP    *pCommandHistory;
  const D3D12_AUTO_BREADCRUMB_NODE1 *pNext;
  struct                            D3D12_AUTO_BREADCRUMB_NODE1;
  UINT                              BreadcrumbContextsCount;
  D3D12_DRED_BREADCRUMB_CONTEXT     *pBreadcrumbContexts;
} D3D12_AUTO_BREADCRUMB_NODE1;