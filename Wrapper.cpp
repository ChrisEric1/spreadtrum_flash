#include "BMPlatform.h"
#include "Wrapper.h"

ClassHandle* createClass() {
    ClassHandle* handle = new ClassHandle;
    handle->obj = new CBootModeOpr();
    return handle;
}

void destroyClass(ClassHandle* handle) {
    delete static_cast<CBootModeOpr*>(handle->obj);
    delete handle;
}

BOOL call_Initialize(ClassHandle* handle, DWORD Port) {
    CBootModeOpr* obj = static_cast<CBootModeOpr*>(handle->obj);
    return obj->Initialize(Port);
}

void call_Uninitialize(ClassHandle* handle) {
    CBootModeOpr* obj = static_cast<CBootModeOpr*>(handle->obj);
    obj->Uninitialize();
}

int call_Read(ClassHandle* handle, UCHAR* m_RecvData, int max_len, int dwTimeout) {
    CBootModeOpr* obj = static_cast<CBootModeOpr*>(handle->obj);
    return obj->Read(m_RecvData, max_len, dwTimeout);
}

int call_Write(ClassHandle* handle, UCHAR* lpData, int iDataSize) {
    CBootModeOpr* obj = static_cast<CBootModeOpr*>(handle->obj);
    return obj->Write(lpData, iDataSize);
}
