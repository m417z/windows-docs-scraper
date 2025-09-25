typedef struct _FIND_NAME_BUFFER {
  UCHAR length;
  UCHAR access_control;
  UCHAR frame_control;
  UCHAR destination_addr[6];
  UCHAR source_addr[6];
  UCHAR routing_info[18];
} FIND_NAME_BUFFER, *PFIND_NAME_BUFFER;