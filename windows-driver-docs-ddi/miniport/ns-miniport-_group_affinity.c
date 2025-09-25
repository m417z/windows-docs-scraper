typedef struct _GROUP_AFFINITY {
  KAFFINITY Mask;
  USHORT    Group;
  USHORT    Reserved[3];
} GROUP_AFFINITY, *PGROUP_AFFINITY;