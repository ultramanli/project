/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package c1;

import javax.swing.JApplet;
import javax.swing.*;
import java.awt.*;

/**
 *
 * @author hp
 */
public class 新建JApplet extends JApplet {

    /**
     * Initialization method that will be called after the applet is loaded into
     * the browser.
     */
    
    JButton jb1=new JButton("1");
    JButton jb2=new JButton("2");
    JLabel j1=new JLabel();
    JLabel j2=new JLabel();
    
    Container cp=getContentPane();
    public void init() {
        
       cp.add(jb1,BorderLayout.CENTER);
       cp.add(jb2);
       cp.add(j1);
        // TODO start asynchronous download of heavy resources
    }

    // TODO overwrite start(), stop() and destroy() methods
}
