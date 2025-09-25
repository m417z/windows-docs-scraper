# IUpdateLockdown::LockDown

## Description

Restricts access to the methods and properties of the object that implements this method.

## Parameters

### `flags` [in]

The option to restrict access to various Windows Update Agent (WUA) objects from the Windows Update website.

Setting this parameter to **uloForWebsiteAccess** or to 1 (one) restricts access to the WUA interfaces that implement the [IUpdateLockdown](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatelockdown) interface.

For a list of the methods and properties that the WUA interfaces restrict when this value is specified, see the "Remarks" section.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The following table identifies the interfaces that implement the [IUpdateLockdown](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatelockdown) interface.

| WUA object | Restricted methods and properties |
| --- | --- |
| [IAutomaticUpdates](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iautomaticupdates) | [Pause](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdates-pause)<br><br>[Resume](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdates-resume) |
| [IAutomaticUpdatesSettings](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iautomaticupdatessettings) | [Save](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings-save) |
| [IUpdate](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate) | [AcceptEula](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdate-accepteula)<br><br>[CopyFromCache](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdate-copyfromcache)<br><br>[CopyToCache](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdate2-copytocache) |
| [IUpdateDownloader](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate) | [BeginDownload](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatedownloader-download)<br><br>[Download](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatedownloader-begindownload)<br><br>[EndDownload](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatedownloader-enddownload)<br><br>[IsForced](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdatedownloader-get_isforced) (cannot set) |
| [IUpdateInstaller](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateinstaller) | [BeginInstall](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-begininstall)<br><br>[BeginUninstall](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-beginuninstall)<br><br>[EndInstall](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-endinstall)<br><br>[EndUninstall](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-enduninstall)<br><br>[Install](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-install)<br><br>[IsForced](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-get_isforced) (cannot set)<br><br>[Uninstall](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-uninstall) |
| [IUpdateServiceManager](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateservicemanager) | [AddScanPackageService](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateservicemanager-addscanpackageservice)<br><br>[RemoveService](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateservicemanager-removeservice)<br><br>[SetOption](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateservicemanager-setoption) |
| [IWebProxy](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iwebproxy) | [Address](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iwebproxy-get_address) (cannot set)<br><br>[AutoDetect](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iwebproxy-get_autodetect) (cannot set)<br><br>[BypassList](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iwebproxy-get_bypasslist) (cannot set)<br><br>[BypassProxyOnLocal](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iwebproxy-get_bypassproxyonlocal) (cannot set)<br><br>[SetPassword](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iwebproxy-setpassword)<br><br>[UserName](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iwebproxy-get_username) (cannot set) |

## See also

[IUpdateLockdown](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatelockdown)