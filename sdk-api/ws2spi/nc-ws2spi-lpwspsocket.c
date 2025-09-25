LPWSPSOCKET Lpwspsocket;

SOCKET Lpwspsocket(
  [in]  int af,
  [in]  int type,
  [in]  int protocol,
  [in]  LPWSAPROTOCOL_INFOW lpProtocolInfo,
  [in]  GROUP g,
        DWORD dwFlags,
  [out] LPINT lpErrno
)
{...}