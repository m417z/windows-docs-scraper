#define  GET_ISO_URB_SIZE(n) (sizeof(struct _URB_ISOCH_TRANSFER)+\
        sizeof(USBD_ISO_PACKET_DESCRIPTOR)*n)