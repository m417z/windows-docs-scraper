# ITsSbTarget::get_IpAddresses

## Description

 Retrieves or specifies the external IP addresses of the target.

This property is read/write.

## Parameters

## Remarks

This property was formerly known as **TargetExternalIpAddresses** in Windows Server 2008 R2.

If the number of external IP addresses is unknown, you can call this method with *sockaddr* set to **NULL**. The method will then return, in the *numAddresses* parameter, the number of [TSSD_ConnectionPoint](https://learn.microsoft.com/windows/win32/api/sessdirpublictypes/ns-sessdirpublictypes-tssd_connectionpoint) structures necessary to receive all the external IP addresses. Allocate the array for *sockaddr* based on this number, and then call the method again, setting *sockaddr* to the newly allocated array and *numAddresses* to the number returned by the first call.

## See also

[ITsSbTarget](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtarget)

[ITsSbTargetEx](https://learn.microsoft.com/windows/desktop/TermServ/itssbtargetex)

[TSSD_ConnectionPoint](https://learn.microsoft.com/windows/win32/api/sessdirpublictypes/ns-sessdirpublictypes-tssd_connectionpoint)