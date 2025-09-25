HRESULT ConnectTerminal(
  [in]      IGraphBuilder *pGraph,
  [in]      DWORD         dwTerminalDirection,
  [in, out] DWORD         *pdwNumPins,
  [out]     IPin          **ppPins
);