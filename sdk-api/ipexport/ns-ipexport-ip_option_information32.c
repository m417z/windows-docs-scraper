typedef struct ip_option_information32 {
  UCHAR Ttl;
  UCHAR Tos;
  UCHAR Flags;
  UCHAR OptionsSize;
  UCHAR POINTER_32 *OptionsData;
} IP_OPTION_INFORMATION32, *PIP_OPTION_INFORMATION32;