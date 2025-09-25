typedef struct tagQACONTAINER {
  ULONG               cbSize;
  IOleClientSite      *pClientSite;
  IAdviseSinkEx       *pAdviseSink;
  IPropertyNotifySink *pPropertyNotifySink;
  IUnknown            *pUnkEventSink;
  DWORD               dwAmbientFlags;
  OLE_COLOR           colorFore;
  OLE_COLOR           colorBack;
  IFont               *pFont;
  IOleUndoManager     *pUndoMgr;
  DWORD               dwAppearance;
  LONG                lcid;
  HPALETTE            hpal;
  IBindHost           *pBindHost;
  IOleControlSite     *pOleControlSite;
  IServiceProvider    *pServiceProvider;
} QACONTAINER;