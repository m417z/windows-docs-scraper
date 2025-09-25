typedef struct _RTM_DEST_INFO {
  RTM_DEST_HANDLE         DestHandle;
  RTM_NET_ADDRESS         DestAddress;
  FILETIME                LastChanged;
  RTM_VIEW_SET            BelongsToViews;
  UINT                    NumberOfViews;
  struct {
    RTM_VIEW_ID       ViewId;
    UINT              NumRoutes;
    RTM_ROUTE_HANDLE  Route;
    RTM_ENTITY_HANDLE Owner;
    DWORD             DestFlags;
    RTM_ROUTE_HANDLE  HoldRoute;
  };
  __unnamed_struct_0201_1 ViewInfo[1];
} RTM_DEST_INFO, *PRTM_DEST_INFO;