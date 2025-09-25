typedef struct _RSVP_FILTERSPEC {
  FilterType Type;
  union {
    RSVP_FILTERSPEC_V4      FilterSpecV4;
    RSVP_FILTERSPEC_V6      FilterSpecV6;
    RSVP_FILTERSPEC_V6_FLOW FilterSpecV6Flow;
    RSVP_FILTERSPEC_V4_GPI  FilterSpecV4Gpi;
    RSVP_FILTERSPEC_V6_GPI  FilterSpecV6Gpi;
  };
} RSVP_FILTERSPEC, *LPRSVP_FILTERSPEC;