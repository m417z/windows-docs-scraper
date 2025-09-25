typedef struct _MPRAPI_ADMIN_DLL_CALLBACKS {
  UCHAR                                            revision;
  PMPRADMINGETIPADDRESSFORUSER                     lpfnMprAdminGetIpAddressForUser;
  PMPRADMINRELEASEIPADRESS                         lpfnMprAdminReleaseIpAddress;
  PMPRADMINGETIPV6ADDRESSFORUSER                   lpfnMprAdminGetIpv6AddressForUser;
  PMPRADMINRELEASEIPV6ADDRESSFORUSER               lpfnMprAdminReleaseIpV6AddressForUser;
  PMPRADMINACCEPTNEWLINK                           lpfnRasAdminAcceptNewLink;
  PMPRADMINLINKHANGUPNOTIFICATION                  lpfnRasAdminLinkHangupNotification;
  PMPRADMINTERMINATEDLL                            lpfnRasAdminTerminateDll;
  PMPRADMINACCEPTNEWCONNECTIONEX                   lpfnRasAdminAcceptNewConnectionEx;
  PMPRADMINACCEPTTUNNELENDPOINTCHANGEEX            lpfnRasAdminAcceptEndpointChangeEx;
  PMPRADMINACCEPTREAUTHENTICATIONEX                lpfnRasAdminAcceptReauthenticationEx;
  PMPRADMINCONNECTIONHANGUPNOTIFICATIONEX          lpfnRasAdminConnectionHangupNotificationEx;
  PMPRADMINRASVALIDATEPREAUTHENTICATEDCONNECTIONEX lpfnRASValidatePreAuthenticatedConnectionEx;
} MPRAPI_ADMIN_DLL_CALLBACKS, *PMPRAPI_ADMIN_DLL_CALLBACKS;