typedef enum _NDIS_RSS_PROFILE {
  NdisRssProfileClosest,
  NdisRssProfileClosestStatic,
  NdisRssProfileNuma,
  NdisRssProfileNumaStatic,
  NdisRssProfileConservative,
  NdisRssProfileBalanced,
  NdisRssProfileMaximum
} NDIS_RSS_PROFILE, *PNDIS_RSS_PROFILE;