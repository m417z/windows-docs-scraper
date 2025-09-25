struct IDxcVersionInfo3 : IUnknown {
  HRESULT GetCustomVersionString(
    char **pVersionString
  );
};