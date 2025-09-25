struct CD3D11_QUERY_DESC1 : D3D11_QUERY_DESC1 {
  void CD3D11_QUERY_DESC1();
  void CD3D11_QUERY_DESC1(
    const D3D11_QUERY_DESC1 & o
  );
  void CD3D11_QUERY_DESC1(
    D3D11_QUERY        query,
    UINT               miscFlags,
    D3D11_CONTEXT_TYPE contextType
  );
  void ~CD3D11_QUERY_DESC1();
};