typedef enum {
    Undetermined = 0,
    Unprotected,
    Protected,
    ProtectedByOtherUser,
    ProtectedToOtherEnterprise,
    NotProtectable,
    ProtectedToOtherIdentity,
    LicenseExpired,
    AccessSuspended,
    FileInUse
} FileProtectionStatus;