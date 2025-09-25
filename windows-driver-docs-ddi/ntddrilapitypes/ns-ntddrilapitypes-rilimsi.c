struct RILIMSI {
  DWORD cbSize;
  DWORD dwParams;
  WCHAR wszImsi[MAXLENGTH_IMSI];
  DWORD dwMcc;
  DWORD dwMnc;
};