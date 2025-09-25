typedef union {
  USN_RECORD_COMMON_HEADER Header;
  USN_RECORD_V2            V2;
  USN_RECORD_V3            V3;
  USN_RECORD_V4            V4;
} USN_RECORD_UNION, *PUSN_RECORD_UNION;