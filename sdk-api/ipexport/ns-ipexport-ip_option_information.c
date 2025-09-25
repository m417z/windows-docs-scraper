typedef struct ip_option_information {
  UCHAR  Ttl;
  UCHAR  Tos;
  UCHAR  Flags;
  UCHAR  OptionsSize;
  PUCHAR OptionsData;
} IP_OPTION_INFORMATION, *PIP_OPTION_INFORMATION;