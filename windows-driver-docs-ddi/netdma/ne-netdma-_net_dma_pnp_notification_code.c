typedef enum _NET_DMA_PNP_NOTIFICATION_CODE {
  NetDmaNotificationProviderRegistered,
  NetDmaNotificationProviderArrival,
  NetDmaNotificationProviderRemoval,
  NetDmaNotificationChannelArrival,
  NetDmaNotificationProviderPowerDown,
  NetDmaNotificationProviderPowerUp,
  NetDmaNotificationMax
} NET_DMA_PNP_NOTIFICATION_CODE, *PNET_DMA_PNP_NOTIFICATION_CODE;