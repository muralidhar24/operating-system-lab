int i,j,temp1,temp2; for(i=0;i<nof;i++)
{
temp1=frm[i]; lrucal[i]=recent[temp1];
}
temp2=lrucal[0]; for(j=1;j<nof;j++)
{
if(temp2>lrucal[j]) temp2=lrucal[j];
}
for(i=0;i<nof;i++)
 if(ref[temp2]==frm[i]) return i;
return 0;
