/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.StackUsingArray;

/**
 *
 * @author sigma
 */
public class StackPointer {
    class node{
        int item ;
        node next;
    }
    node top,temp ;

    public StackPointer() {top = null ;}
    void push(int newitem)
    {
        node newItem = new node();
        newItem.item = newitem ;
        newItem.next = top ; 
        top = newItem ;
    }
    boolean isEmpty()
    {
        return top==null ;
    }
    void pop()
    {
        if(isEmpty()) System.out.println("Empty stack");
        else {
        temp = top ;
        top = top.next ; }
    }
    void pop(int stackTop)
    {
        if(isEmpty()) System.out.println("Empty stack");
        else {
        temp = top ;
        top = top.next ;
        stackTop = temp.item ;}
    }
    
    void display()
    {
        node cur = top ;
        while(cur != null)
        {
            System.out.print(cur.item + " ");
            cur = cur.next ;
        }
        System.out.println("");
        
    }
    
}
