typedef struct NMSEARCHWEB {
  NMHDR                   hdr;
  EC_SEARCHWEB_ENTRYPOINT entrypoint;
  BOOL                    hasQueryText;
  BOOL                    invokeSucceeded;
} NMSEARCHWEB;