#include "stdafx.h"

class DDContext;

class DDSyncManager : public IHostSyncManager {
private:
	volatile LONG m_cRef;
	ICLRSyncManager *m_pCLRSyncManager;
    DDContext *m_pContext;

public:
    DDSyncManager(DDContext *pContext);
    ~DDSyncManager();

    ICLRSyncManager* GetCLRSyncManager() {
		m_pCLRSyncManager->AddRef();
		return m_pCLRSyncManager;
	}

	// IUnknown functions
	STDMETHODIMP_(DWORD) AddRef();
	STDMETHODIMP_(DWORD) Release();
	STDMETHODIMP QueryInterface(const IID &riid, void **ppvObject);

	// IHostSyncManager functions
    STDMETHODIMP SetCLRSyncManager(/* in */ ICLRSyncManager *pManager);
    STDMETHODIMP CreateCrst(/* out */ IHostCrst **ppCrst);
    STDMETHODIMP CreateCrstWithSpinCount(/* in */ DWORD dwSpinCount, /* out */ IHostCrst **ppCrst);
    STDMETHODIMP CreateAutoEvent(/* out */IHostAutoEvent **ppEvent);    
    STDMETHODIMP CreateManualEvent(/* in */ BOOL bInitialState, /* out */ IHostManualEvent **ppEvent);    
    STDMETHODIMP CreateMonitorEvent(/* in */ SIZE_T Cookie, /* out */ IHostAutoEvent **ppEvent);
    STDMETHODIMP CreateRWLockWriterEvent(/* in */ SIZE_T Cookie, /* out */ IHostAutoEvent **ppEvent);    
    STDMETHODIMP CreateRWLockReaderEvent(/* in */ BOOL bInitialState, /* in */ SIZE_T Cookie, /* out */ IHostManualEvent **ppEvent);    
    STDMETHODIMP CreateSemaphore(/* in */ DWORD dwInitial, /* in */ DWORD dwMax, /* out */ IHostSemaphore **ppSemaphore);
};