struct IDirect3DDxgiInterfaceAccess : IUnknown {
  HRESULT GetInterface(
    REFIID iid,
    void   **p
  );
};