# WELL_KNOWN_SID_TYPE enumeration

## Description

The **WELL_KNOWN_SID_TYPE** enumeration is a list of commonly used [security identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIDs). Programs can pass these values to the [CreateWellKnownSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createwellknownsid) function to create a SID from this list.

## Constants

### `WinNullSid:0`

Indicates a null SID.

### `WinWorldSid:1`

Indicates a SID that matches everyone.

### `WinLocalSid:2`

Indicates a local SID.

### `WinCreatorOwnerSid:3`

Indicates a SID that matches the owner or creator of an object.

### `WinCreatorGroupSid:4`

Indicates a SID that matches the creator group of an object.

### `WinCreatorOwnerServerSid:5`

Indicates a creator owner server SID.

### `WinCreatorGroupServerSid:6`

Indicates a creator group server SID.

### `WinNtAuthoritySid:7`

Indicates a SID for the Windows NT authority account.

### `WinDialupSid:8`

Indicates a SID for a dial-up account.

### `WinNetworkSid:9`

Indicates a SID for a network account. This SID is added to the process of a token when it logs on across a network. The corresponding logon type is LOGON32_LOGON_NETWORK.

### `WinBatchSid:10`

Indicates a SID for a batch process. This SID is added to the process of a token when it logs on as a batch job. The corresponding logon type is LOGON32_LOGON_BATCH.

### `WinInteractiveSid:11`

Indicates a SID for an interactive account. This SID is added to the process of a token when it logs on interactively. The corresponding logon type is LOGON32_LOGON_INTERACTIVE.

### `WinServiceSid:12`

Indicates a SID for a service. This SID is added to the process of a token when it logs on as a service. The corresponding logon type is LOGON32_LOGON_SERVICE.

### `WinAnonymousSid:13`

Indicates a SID for the anonymous account.

### `WinProxySid:14`

Indicates a proxy SID.

### `WinEnterpriseControllersSid:15`

Indicates a SID for an enterprise controller.

### `WinSelfSid:16`

Indicates a SID for self.

### `WinAuthenticatedUserSid:17`

Indicates a SID that matches any authenticated user.

### `WinRestrictedCodeSid:18`

Indicates a SID for restricted code.

### `WinTerminalServerSid:19`

Indicates a SID that matches a terminal server account.

### `WinRemoteLogonIdSid:20`

Indicates a SID that matches remote logons.

### `WinLogonIdsSid:21`

Indicates a SID that matches logon IDs.

### `WinLocalSystemSid:22`

Indicates a SID that matches the local system.

### `WinLocalServiceSid:23`

Indicates a SID that matches a local service.

### `WinNetworkServiceSid:24`

Indicates a SID that matches a network service.

### `WinBuiltinDomainSid:25`

Indicates a SID that matches the domain account.

### `WinBuiltinAdministratorsSid:26`

Indicates a SID that matches the administrator group.

### `WinBuiltinUsersSid:27`

Indicates a SID that matches built-in user accounts.

### `WinBuiltinGuestsSid:28`

Indicates a SID that matches the guest account.

### `WinBuiltinPowerUsersSid:29`

Indicates a SID that matches the power users group.

### `WinBuiltinAccountOperatorsSid:30`

Indicates a SID that matches the account operators account.

### `WinBuiltinSystemOperatorsSid:31`

Indicates a SID that matches the system operators group.

### `WinBuiltinPrintOperatorsSid:32`

Indicates a SID that matches the print operators group.

### `WinBuiltinBackupOperatorsSid:33`

Indicates a SID that matches the backup operators group.

### `WinBuiltinReplicatorSid:34`

Indicates a SID that matches the replicator account.

### `WinBuiltinPreWindows2000CompatibleAccessSid:35`

Indicates a SID that matches pre-Windows 2000 compatible accounts.

### `WinBuiltinRemoteDesktopUsersSid:36`

Indicates a SID that matches remote desktop users.

### `WinBuiltinNetworkConfigurationOperatorsSid:37`

Indicates a SID that matches the network operators group.

### `WinAccountAdministratorSid:38`

Indicates a SID that matches the account administrator's account.

### `WinAccountGuestSid:39`

Indicates a SID that matches the account guest group.

### `WinAccountKrbtgtSid:40`

Indicates a SID that matches account Kerberos target group.

### `WinAccountDomainAdminsSid:41`

Indicates a SID that matches the account domain administrator group.

### `WinAccountDomainUsersSid:42`

Indicates a SID that matches the account domain users group.

### `WinAccountDomainGuestsSid:43`

Indicates a SID that matches the account domain guests group.

### `WinAccountComputersSid:44`

Indicates a SID that matches the account computer group.

### `WinAccountControllersSid:45`

Indicates a SID that matches the account controller group.

### `WinAccountCertAdminsSid:46`

Indicates a SID that matches the certificate administrators group.

### `WinAccountSchemaAdminsSid:47`

Indicates a SID that matches the schema administrators group.

### `WinAccountEnterpriseAdminsSid:48`

Indicates a SID that matches the enterprise administrators group.

### `WinAccountPolicyAdminsSid:49`

Indicates a SID that matches the policy administrators group.

### `WinAccountRasAndIasServersSid:50`

Indicates a SID that matches the RAS and IAS server account.

### `WinNTLMAuthenticationSid:51`

Indicates a SID present when the Microsoft NTLM authentication package authenticated the client.

### `WinDigestAuthenticationSid:52`

Indicates a SID present when the Microsoft Digest authentication package authenticated the client.

### `WinSChannelAuthenticationSid:53`

Indicates a SID present when the Secure Channel (SSL/TLS) authentication package authenticated the client.

### `WinThisOrganizationSid:54`

Indicates a SID present when the user authenticated from within the forest or across a trust that does not have the selective authentication option enabled. If this SID is present, then WinOtherOrganizationSid cannot be present.

### `WinOtherOrganizationSid:55`

Indicates a SID present when the user authenticated across a forest with the selective authentication option enabled. If this SID is present, then WinThisOrganizationSid cannot be present.

### `WinBuiltinIncomingForestTrustBuildersSid:56`

Indicates a SID that allows a user to create incoming forest trusts. It is added to the token of users who are a member of the Incoming Forest Trust Builders built-in group in the root domain of the forest.

### `WinBuiltinPerfMonitoringUsersSid:57`

Indicates a SID that matches the performance monitor user group.

### `WinBuiltinPerfLoggingUsersSid:58`

Indicates a SID that matches the performance log user group.

### `WinBuiltinAuthorizationAccessSid:59`

Indicates a SID that matches the Windows Authorization Access group.

### `WinBuiltinTerminalServerLicenseServersSid:60`

Indicates a SID is present in a server that can issue terminal server licenses.

### `WinBuiltinDCOMUsersSid:61`

Indicates a SID that matches the distributed COM user group.

### `WinBuiltinIUsersSid:62`

Indicates a SID that matches the Internet built-in user group.

### `WinIUserSid:63`

Indicates a SID that matches the Internet user group.

### `WinBuiltinCryptoOperatorsSid:64`

Indicates a SID that allows a user to use cryptographic operations. It is added to the token of users who are a member of the CryptoOperators built-in group.

### `WinUntrustedLabelSid:65`

Indicates a SID that matches an untrusted label.

### `WinLowLabelSid:66`

Indicates a SID that matches a low level of trust label.

### `WinMediumLabelSid:67`

Indicates a SID that matches a medium level of trust label.

### `WinHighLabelSid:68`

Indicates a SID that matches a high level of trust label.

### `WinSystemLabelSid:69`

Indicates a SID that matches a system label.

### `WinWriteRestrictedCodeSid:70`

Indicates a SID that matches a write restricted code group.

### `WinCreatorOwnerRightsSid:71`

Indicates a SID that matches a creator and owner rights group.

### `WinCacheablePrincipalsGroupSid:72`

Indicates a SID that matches a cacheable principals group.

### `WinNonCacheablePrincipalsGroupSid:73`

Indicates a SID that matches a non-cacheable principals group.

### `WinEnterpriseReadonlyControllersSid:74`

Indicates a SID that matches an enterprise wide read-only controllers group.

### `WinAccountReadonlyControllersSid:75`

Indicates a SID that matches an account read-only controllers group.

### `WinBuiltinEventLogReadersGroup:76`

Indicates a SID that matches an event log readers group.

### `WinNewEnterpriseReadonlyControllersSid:77`

Indicates a SID that matches a read-only enterprise domain controller.

### `WinBuiltinCertSvcDComAccessGroup:78`

Indicates a SID that matches the built-in DCOM certification services access group.

### `WinMediumPlusLabelSid:79`

Indicates a SID that matches the medium plus integrity label.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not available.

### `WinLocalLogonSid:80`

Indicates a SID that matches a local logon group.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not available.

### `WinConsoleLogonSid:81`

Indicates a SID that matches a console logon group.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not available.

### `WinThisOrganizationCertificateSid:82`

Indicates a SID that matches a certificate for the given organization.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not available.

### `WinApplicationPackageAuthoritySid:83`

Indicates a SID that matches the application package authority.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not available.

### `WinBuiltinAnyPackageSid:84`

Indicates a SID that applies to all app containers.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not available.

### `WinCapabilityInternetClientSid:85`

Indicates a SID of Internet client capability for app containers.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not available.

### `WinCapabilityInternetClientServerSid:86`

Indicates a SID of Internet client and server capability for app containers.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not available.

### `WinCapabilityPrivateNetworkClientServerSid:87`

Indicates a SID of private network client and server capability for app containers.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not available.

### `WinCapabilityPicturesLibrarySid:88`

Indicates a SID for pictures library capability for app containers.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not available.

### `WinCapabilityVideosLibrarySid:89`

Indicates a SID for videos library capability for app containers.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not available.

### `WinCapabilityMusicLibrarySid:90`

Indicates a SID for music library capability for app containers.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not available.

### `WinCapabilityDocumentsLibrarySid:91`

Indicates a SID for documents library capability for app containers.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not available.

### `WinCapabilitySharedUserCertificatesSid:92`

Indicates a SID for shared user certificates capability for app containers.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not available.

### `WinCapabilityEnterpriseAuthenticationSid:93`

Indicates a SID for Windows credentials capability for app containers.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not available.

### `WinCapabilityRemovableStorageSid:94`

Indicates a SID for removable storage capability for app containers.

**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not available.

### `WinBuiltinRDSRemoteAccessServersSid:95`

### `WinBuiltinRDSEndpointServersSid:96`

### `WinBuiltinRDSManagementServersSid:97`

### `WinUserModeDriversSid:98`

### `WinBuiltinHyperVAdminsSid:99`

### `WinAccountCloneableControllersSid:100`

### `WinBuiltinAccessControlAssistanceOperatorsSid:101`

### `WinBuiltinRemoteManagementUsersSid:102`

### `WinAuthenticationAuthorityAssertedSid:103`

### `WinAuthenticationServiceAssertedSid:104`

### `WinLocalAccountSid:105`

### `WinLocalAccountAndAdministratorSid:106`

### `WinAccountProtectedUsersSid:107`

### `WinCapabilityAppointmentsSid:108`

### `WinCapabilityContactsSid:109`

### `WinAccountDefaultSystemManagedSid:110`

### `WinBuiltinDefaultSystemManagedGroupSid:111`

### `WinBuiltinStorageReplicaAdminsSid:112`

### `WinAccountKeyAdminsSid:113`

### `WinAccountEnterpriseKeyAdminsSid:114`

### `WinAuthenticationKeyTrustSid:115`

### `WinAuthenticationKeyPropertyMFASid:116`

### `WinAuthenticationKeyPropertyAttestationSid:117`

### `WinAuthenticationFreshKeyAuthSid:118`

### `WinBuiltinDeviceOwnersSid:119`

## See also

[Allowing Anonymous Access](https://learn.microsoft.com/windows/desktop/SecAuthZ/allowing-anonymous-access)

[CreateWellKnownSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createwellknownsid)

[IsWellKnownSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-iswellknownsid)

[Well-known SIDs](https://learn.microsoft.com/windows/desktop/SecAuthZ/well-known-sids)