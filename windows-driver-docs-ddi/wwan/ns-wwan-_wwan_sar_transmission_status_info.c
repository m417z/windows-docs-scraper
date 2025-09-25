typedef struct _WWAN_SAR_TRANSMISSION_STATUS_INFO {
  WWAN_SAR_TRANSMISSION_STATUS_NOTIFICATION_STATE ChannelNotification;
  WWAN_SAR_TRANSMISSION_STATUS                    TransmissionStatus;
  ULONG                                           HysteresisTimer;
} WWAN_SAR_TRANSMISSION_STATUS_INFO, *PWWAN_SAR_TRANSMISSION_STATUS_INFO;