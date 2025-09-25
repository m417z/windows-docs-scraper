struct CD3D11_QUERY_DESC : D3D11_QUERY_DESC {
  void CD3D11_QUERY_DESC();
  void CD3D11_QUERY_DESC(
    const D3D11_QUERY_DESC & o
  );
  void CD3D11_QUERY_DESC(
    D3D11_QUERY query,
    UINT        miscFlags
  );
  void ~CD3D11_QUERY_DESC();
};