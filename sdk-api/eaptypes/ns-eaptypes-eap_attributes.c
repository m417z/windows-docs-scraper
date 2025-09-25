typedef struct _EAP_ATTRIBUTES {
  DWORD         dwNumberOfAttributes;
#if ...
  EAP_ATTRIBUTE *pAttribs;
#else
  EAP_ATTRIBUTE *pAttribs;
#endif
} EAP_ATTRIBUTES, EapAttributes;