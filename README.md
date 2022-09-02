# File_recovery_system_in_xv6OS

A university project we had as homework. Original project text is in the "OS Domaci 2" file.

I added a recovery system in xv6OS

This is once again a university project we had to do. 
To run this project you have to be on a linux OS
because the QEMU virtual machine won't run on a Windows machine.
Simply go to the directory of the project you cloned from the repo
and type "make qemu" into your console. If you notice something went
wrong while you were using the QEMU vm simply type "make clean" before
running QEMU with "make qemu" again.

To test the recovery functionality i added a program called writer.
To use it write "writer file_name file_size_in_bytes".
For example "writer a 10" will make a file named a with 10 'a' letters
in the current directory.
Writer switches the letter it uses by one each time it passes 12 bytes
so the 513 byte will be letter b instead of a.
You can read the file you created with "cat a" function.
Now delete the file you created. You can see the deleted files that
can be recovered in the current directory by writing "lsdel", or in
another directory by typing "lsdel directory_path". Lsdel is another
program I added to xv6.
Now to recover any of the files that can be recovered (are listed by lsdel)
type "rec file_name". If the file was restored the message
"Inode restored successfully" will be shown. You can again use the file
like it was never deleted before. Try reading it again with cat and see
what happens.
