typedef struct CF_SYNC_POLICIES {
  ULONG                            StructSize;
  CF_HYDRATION_POLICY              Hydration;
  CF_POPULATION_POLICY             Population;
  CF_INSYNC_POLICY                 InSync;
  CF_HARDLINK_POLICY               HardLink;
  CF_PLACEHOLDER_MANAGEMENT_POLICY PlaceholderManagement;
} CF_SYNC_POLICIES;