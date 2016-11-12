SETUP PROJECT FOR MATLAB. NOTE: YOU HAVE TO HAVE MATLAB INSTALLED ON YOUR MACHINE 

In MATLAB, type the following commands:

>> matlabroot
>> compute(‘arch’)
Use these values for $MATLABROOT and $ARCH in the following steps. 

1. Open Microsoft Visual Studio and select New Project…

2. Navigate to the installed templates for the Visual C++ language and select Win32 Console Application.

3. Name the project engwindemo and specify a location in the text fields, then click OK.

4. Copy the engwindemo.c code. To view the source code, in MATLAB type:

      >> edit(fullfile(matlabroot,'extern','examples','eng_mat','engwindemo.c'))
5. Open project Property Pages. From the PROJECT menu, select engwindemo Properties… and expand the Configuration Properties option.

6. Open C/C++-> General. In the ADDITIONAL INCLUDE DIRECTORIES field, navigate to your matlabroot directory and select \extern\include.

7. Open C/C++->Precompiled Headers, and select "Not Using Precompiled Headers" from the drop-down list in the Precompiled Header field. 

8. Open Linker->General. In the ADDITIONAL LIBRARY DIRECTORIES field, navigate to your matlabroot directory and select \extern\lib\$ARCH\microsoft.

9. Open Debugging. In the Environment field, set the PATH variable to:

$MATLABROOT\bin\$ARCH;
For example, add: 

PATH=C:\Program Files\MATLAB\R2014b\bin\win64;
Make sure to append “;” to the path name.

10. Open Linker->Input. Add the following library names to the ADDITIONAL DEPENDENCIES field.

libmx.lib
libmat.lib
libeng.lib
11. Close the Property Pages.

12. For 64-bit applications, select Build ->Configuration Manager and set the value of the Active solution platform field from the drop-down list to x64.

13. Open the Windows Command Processor and update the Windows system PATH environment variable. Do this every time your build your application.

set PATH = $MATLABROOT\bin\$ARCH;%PATH%
To permanently set this value, click the Windows Start icon -> Right click on Computer -> Properties -> Advanced System Settings -> Environment variables -> System Variables -> Open "Path" for editing. Add a variable of the format::

$MATLABROOT\bin\$ ARCH
Note: If the machine has more than one MATLAB installed, the directory for the target release and platform must be ahead of any other MATLAB directory (for instance, when compiling a 64-bit application, the directory in the MATLAB 64-bit installation must be the first one on the PATH).

14. Build and execute the application