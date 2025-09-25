typedef struct _RTM_ROUTE_INFO {
  RTM_DEST_HANDLE    DestHandle;
  RTM_ENTITY_HANDLE  RouteOwner;
  RTM_NEXTHOP_HANDLE Neighbour;
  UCHAR              State;
  UCHAR              Flags1;
  USHORT             Flags;
  RTM_PREF_INFO      PrefInfo;
  RTM_VIEW_SET       BelongsToViews;
  PVOID              EntitySpecificInfo;
  RTM_NEXTHOP_LIST   NextHopsList;
} RTM_ROUTE_INFO, *PRTM_ROUTE_INFO;