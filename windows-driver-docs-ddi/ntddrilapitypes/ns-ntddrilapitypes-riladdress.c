struct RILADDRESS {
  DWORD cbSize;
  DWORD dwParams;
  DWORD dwType;
  DWORD dwNumPlan;
  WCHAR wszAddress[MAXLENGTH_ADDRESS];
};