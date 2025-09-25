# SERVICE_DELAYED_AUTO_START_INFO structure

## Description

Contains the delayed auto-start setting of an auto-start service.

## Members

### `fDelayedAutostart`

If this member is **TRUE**, the service is started after other auto-start services are started plus a short delay. Otherwise, the service is started during system boot.

This setting is ignored unless the service is an auto-start service.

## Remarks

Any service can be marked as a delayed auto-start service; however, this setting has no effect unless the service is an auto-start service. The change takes effect the next time the system is started.

The service control manager (SCM) supports delayed auto-start services to improve system performance at boot time without affecting the user experience. The SCM makes a list of delayed auto-start services during boot and starts them one at a time after the delay has passed, honoring dependencies. There is no specific time guarantee as to when the service will be started. To minimize the impact on the user, the [ServiceMain](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lpservice_main_functiona) thread for the service is started with THREAD_PRIORITY_LOWEST. Threads that are started by the *ServiceMain* thread should also be run at a low priority. After the service has reported that it has entered the SERVICE_RUNNING state, the priority of the *ServiceMain* thread is raised to THREAD_PRIORITY_NORMAL.

A delayed auto-start service cannot be a member of a load ordering group. It can depend on another auto-start service. An auto-start service can depend on a delayed auto-start service, but this is not generally desirable as the SCM must start the dependent delayed auto-start service at boot.

If a delayed auto-start service is demand-started using the [StartService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-startservicea) function shortly after boot, the system starts the service on demand instead of delaying its start further. If this situation is likely to occur on a regular basis, the service should not be marked as a delayed auto-start service.

If a client calls a delayed auto-start service before it is loaded, the call fails. Therefore, clients should be prepared to either retry the call or demand start the service.

## See also

[ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a)

[QueryServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfig2a)