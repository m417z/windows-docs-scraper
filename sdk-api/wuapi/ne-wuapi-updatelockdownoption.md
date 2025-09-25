# UpdateLockdownOption enumeration

## Description

Defines the functionality that the Windows Update Agent (WUA) object can access from Windows Update.

## Constants

### `uloForWebsiteAccess:0x1`

If access is from Windows Update, restrict access to the WUA interfaces that implement the [IUpdateLockdown](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatelockdown) interface.

## Remarks

In the following table, the first column lists the interfaces that implement the [IUpdateLockdown](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatelockdown) interface. The second column lists the methods and properties that are restricted by the WUA interfaces when a value is specified for **uloForWebsiteAccess**.

| WUA object | Restricted methods and properties |
| --- | --- |
| [IAutomaticUpdates](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iautomaticupdates) | [Pause](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdates-pause)<br><br>[Resume](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdates-resume) |
| [IAutomaticUpdatesSettings](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iautomaticupdatessettings) | [Save](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings-save) |
| [IUpdate](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate) | [AcceptEula](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdate-accepteula)<br><br>[CopyFromCache](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdate-copyfromcache)<br><br>[CopyToCache](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdate2-copytocache) |
| [IUpdateDownloader](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatedownloader) | [Download](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatedownloader-download)<br><br>[BeginDownload](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatedownloader-begindownload)<br><br>[EndDownload](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatedownloader-enddownload)<br><br>[IsForced](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatedownloader-get_isforced) (cannot set) |
| [IUpdateInstaller](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateinstaller) | [BeginInstall](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-begininstall)<br><br>[BeginUninstall](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-beginuninstall)<br><br>[EndInstall](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-endinstall)<br><br>[EndUninstall](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-enduninstall)<br><br>[Install](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-install)<br><br>[IsForced](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-get_isforced) (cannot set)<br><br>[Uninstall](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-uninstall) |
| [IUpdateServiceManager](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateservicemanager) | [AddScanPackageService](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateservicemanager-addscanpackageservice)<br><br>[RemoveService](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateservicemanager-removeservice)<br><br>[SetOption](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateservicemanager-setoption) |
| [IWebProxy](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iwebproxy) | [Address](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iwebproxy-get_address) (cannot set)<br><br>[AutoDetect](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iwebproxy-get_autodetect) (cannot set)<br><br>[BypassList](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iwebproxy-get_bypasslist) (cannot set)<br><br>[BypassProxyOnLocal](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iwebproxy-get_bypassproxyonlocal) (cannot set)<br><br>[SetPassword](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iwebproxy-setpassword)<br><br>[UserName](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iwebproxy-get_username) (cannot set) |

## See also

[IUpdateLockdown::LockDown](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatelockdown-lockdown)