typedef enum _NL_ROUTE_ORIGIN {
  NlroManual,
  NlroWellKnown,
  NlroDHCP,
  NlroRouterAdvertisement,
  Nlro6to4
} NL_ROUTE_ORIGIN, *PNL_ROUTE_ORIGIN;